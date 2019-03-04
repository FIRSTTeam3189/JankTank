/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Utils/UartServer.h"
#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
//#include "Constants.h"

namespace Utils
{
UartServer::UartServer()
{
}

void UartServer::recieveData(frc::SerialPort *uart, VisionData *data, bool *running, std::chrono::milliseconds *time)
{
    int count = 0;
    std::vector<char> localBuffer;
    int state = BUFFER_STATE_WAIT_FOR_SYNC;
    char rawData[sizeof(VisionData) + sizeof(SYNC_BYTES) + sizeof(TAIL_BYTE)];
    while (*running)
    {
        // Clear out rawData via memset here.
        memset(&rawData[0], 0, sizeof(rawData));
        int size = uart->Read(rawData, sizeof(VisionData)); // Sizeof(VisionData) should be the sizeof the localBuffer you're storing into
        frc::SmartDashboard::PutNumber("UARTcount ", count);
        //fills up the que with the rawData data
        for (int i = 0; i < size; i++)
        {
            count++;
            std::cout << rawData[i] << std::endl;
            localBuffer.push_back(rawData[i]);
        }
        switch (state)
        {
        case BUFFER_STATE_WAIT_FOR_SYNC:
            //checks to see if we have enough bytes to check and breaks the scope if we do
            if (localBuffer.size() < sizeof(SYNC_BYTES))
            {
                break;
            }
            if (localBuffer[0] == SYNC_BYTES[0] && localBuffer[1] == SYNC_BYTES[1])
            {
                localBuffer.erase(localBuffer.begin(), localBuffer.begin() + 2);
                state = BUFFER_STATE_WAIT_FOR_TAIL;
            }
            else
            {
                localBuffer.erase(localBuffer.begin());
            }
            break;
        case BUFFER_STATE_WAIT_FOR_TAIL:
            std::cout << "tail" << std::endl;
            int messageSize = sizeof(VisionData) + sizeof(TAIL_BYTE);
            if (localBuffer.size() < messageSize)
            {
                break;
            }
            if (localBuffer[messageSize - 2] == TAIL_BYTE[0] && localBuffer[messageSize - 1] == TAIL_BYTE[1])
            { // remember the size is a bigger number than the last index
                //*(time) = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

                //copies the data directly from localBuffer to data  b
                memcpy(data, localBuffer.data(), sizeof(VisionData));

                //TODO remove bytes that have been processed
                localBuffer.erase(localBuffer.begin(), localBuffer.begin() + messageSize);
                state = BUFFER_STATE_WAIT_FOR_SYNC;
                break;
            }
        }
    }
}

void UartServer::start()
{
    UartServer::Uart = new frc::SerialPort(115200, frc::SerialPort::Port::kMXP);
    UartServer::data = new VisionData();
    UartServer::running = new bool;
    *(UartServer::running) = true;
    UartServer::thread = nullptr;
    static std::thread t(&recieveData, Uart, data, running, lastRecieved);
    UartServer::thread = &t;
}

void UartServer::stop()
{
    *(running) = false;
}

VisionData UartServer::getData()
{
    return *UartServer::data;
}

UartServer &UartServer::getInstance()
{
    static UartServer i;
    return i;
}

} // namespace Utils
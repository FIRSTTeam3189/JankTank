/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Utils/UartServer.h"
#include "Constants.h"

namespace Utils
{
UartServer::UartServer()
{
    Uart = new frc::SerialPort(BAUD_RATE, frc::SerialPort::Port::kMXP);
}

void UartServer::recieveData(std::queue<char> *queue, VisionData *Data, bool *running, frc::SerialPort *uart)
{

    while (running)
    {
        //getting the raw data from the uart
        char *raw;
        int size = uart->Read(raw, sizeof(VisionData));
        //fills up the que with the raw data
        for (int i = 0; i < size; i++)
        {
            queue->push(raw[i]);
        }
        //checks whether the front byte is the sync byte and forgets it if it isn't
        while ((!queue->empty()) && !(queue->front() == SYNC_BYTES))
        {
            queue->pop();
        }

        //checks to see if the data we are getting is good then fills a tempory array with queue if it is
        if (!queue->empty() && queue->front() == SYNC_BYTES && queue->size() - 1 == sizeof(VisionData))
        {
            queue->pop();
            char temp[sizeof(VisionData)];
            for (int i = 0; i < sizeof(VisionData); i++)
            {
                temp[i] = queue->front();
                queue->pop();
            }
            //parses temp array into a VisionData type and makes myData equal to it
            *(Data) = *((VisionData *)temp);
        }
    }
}

void UartServer::start()
{
    std::thread t(&recieveData, queue, myData, running, Uart);
    myThread = &t;
}

void UartServer::stop()
{
    *(running) = false;
}

VisionData UartServer::getData()
{
    return *myData;
}

} // namespace Utils
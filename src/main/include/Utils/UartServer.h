/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <thread>
#include <chrono>
#include <mutex>
#include <memory>
#include <frc/SerialPort.h>
#include <queue>

namespace Utils
{
constexpr char SYNC_BYTES = 0xFC;

#pragma pack(push,1)
struct VisionData
{
  double x;
  double y;
};
#pragma pack(pop)
class UartServer
{
public:
  UartServer();
  bool sendData();
  VisionData getData();
  void start();
  void stop();

private:
  //the data that is being sent
  VisionData *myData;
  //a seprate thread to run the Uart code to ensure that it doesn't block or interupt the robot code
  std::thread *myThread;
  //bool to store if we are running or not
  bool *running;
  //the memory storage where we are storing the incoming bytes
  std::queue<char> *queue;
  //Initilizes pins on roborio and communicates with the OS
  frc::SerialPort *Uart;
  //the function to recieve data implementing all of the previous objects
  static void recieveData(std::queue<char> *, VisionData *, bool *,frc::SerialPort *uart);
};
} // namespace Utils
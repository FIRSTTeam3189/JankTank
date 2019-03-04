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
constexpr char SYNC_BYTES[2] = {0xFC, 0xA0};
constexpr char TAIL_BYTE[2] = {0xFC, 0xA1};
constexpr int BAUD_RATE = 115200;
#define BUFFER_STATE_WAIT_FOR_SYNC 0
#define BUFFER_STATE_WAIT_FOR_TAIL 1
#pragma pack(push, 1)
struct VisionData
{
  //for now "distance" is going to return distance from the center of the camera screen from -1280 to 1280. Negative is left.
  //x is first distance needed to travel
  double x;
  //y is second distance needed to travel
  double y;
  //distance from center of targets, error basically
  double distance;
  //distance from targets. Not sure if accuarate.
  double depth;
  //angle needed to move to be perpendicular with target. given in degrees. (NOT RADIANS)
  double angle;
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
  UartServer(UartServer const&) = delete;
  void operator=(UartServer const&) = delete;
  static UartServer& getInstance();

private:
  std::chrono::milliseconds *lastRecieved;
  //the data that is being sent
  VisionData *data;
  //a seperate thread to run the Uart code to ensure that it doesn't block or interupt the robot code
  std::thread *thread;
  //bool to store if we are running or not
  bool *running;
  //Initilizes pins on roborio and communicates with the OS
  frc::SerialPort *Uart;
  //the function to recieve data implementing all of the previous objects
  static void recieveData(frc::SerialPort *, VisionData *, bool *, std::chrono::milliseconds *);
};
} // namespace Utils

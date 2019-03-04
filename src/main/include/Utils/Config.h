// #pragma once

// #include <string>
// #include <functional>
// #include <unordered_map>
// #include <frc/smartdashboard/SmartDashboard.h>
// #include "frc/shuffleboard/ShuffleboardTab.h"
// #include "frc/shuffleboard/Shuffleboard.h"

// class ConfigMember {
// public:
//     // Each member has a function to get the value from some place (using function callback)
//     //    and another function callback to set the member.
//     // This will be used in conjunction with the SmartDashboard Get/Set number methods to pull
//     //    the values from the SmartDashboard instead of proxying them to this member class.
//     ConfigMember(std::function<double(void)> get_member,
//                  std::function<void(double)> set_member,
//                  std::string name);

//     //ConfigMember(const ConfigMember& other);

    
//     // Gets the data member from the get function callback, usually will be calling the 
//     //    GetNumber callback on the smart dashboard.
//     double get();

//     // Sets the member in the config file using the set method, usually will be calling
//     //    SetNumber callback on the smart dashboard.
//     void set(double);

//     // Gets the name of the member of the config file. Usually this will be the name of
//     //   the smartdashboard entry.
//     const std::string& name();
// private:
//     const std::string m_name;
//     std::function<double(void)> m_get_member;
//     std::function<void(double)> m_set_member;
// };

// class ConfigFile {
//     public:
//         ConfigFile(std::string smartdashboardTab, std::string filename);

//         // Adds a new member to the configuration file. Will add the same member to the smart dashboard.
//         void add_member(std::string name, double default_value);

//         // Loads a configuration from the filename given earlier
//         void load_config();

//         // Saves the configuration to file.
//         void save_config();

//         // Access each config member of the class.
//         // This will allow you to use conf['config_member_name'].get()
//         ConfigMember& operator[](const std::string& key);
//     private:
//         const std::string m_filename;
//         frc::ShuffleboardTab& m_tab;
//         std::unordered_map<std::string, ConfigMember> m_tabMembers;
// };
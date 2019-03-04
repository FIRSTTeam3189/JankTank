// #include "Utils/Config.h"
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// #include <frc/smartdashboard/SmartDashboard.h>
// #include "frc/shuffleboard/ShuffleboardTab.h"
// #include "frc/shuffleboard/Shuffleboard.h"


// ConfigMember::ConfigMember(std::function<double(void)> getter,
//                            std::function<void(double)> setter,
//                            std::string name) : m_get_member(getter),
//                                                m_set_member(setter),
//                                                m_name(name) {}

// double ConfigMember::get() {
//     // Just returns the result of the getter
//     return m_get_member();
// }

// void ConfigMember::set(double value) {
//     // Just calls the setter
//     m_set_member(value);
// }

// const std::string& ConfigMember::name() {
//     return m_name;
// }

// ConfigFile::ConfigFile(std::string smartdashboardTab, 
//                        std::string filename) : m_tab(frc::Shuffleboard::GetTab(smartdashboardTab)),
//                                                m_filename(filename),
//                                                m_tabMembers() {}

// void ConfigFile::add_member(std::string name, double default_value) {
//     if (m_tabMembers.find(name) != m_tabMembers.end()) {
//         std::cout << name << " already exists in " << m_tab.GetTitle() << std::endl;
//         return;
//     }

//     // Add a new tab member
//     auto& entry = m_tab.Add(name, default_value);
//     m_tabMembers[name] = ConfigMember(std::bind(&nt::NetworkTableEntry::GetDouble, entry, 0),
//                                       std::bind(&nt::NetworkTableEntry::SetDouble, entry, 0),
//                                       name);
// }

// void ConfigFile::load_config() {
//     // Sort keys by name
//     std::vector<std::string> keys;
//     for (auto &it : m_tabMembers) {
//         keys.push_back(it.first);
//     }
//     std::sort(keys.begin(), keys.end());

//     // See if file exists, if don't, then don't load it.
//     std::ifstream conf;
//     conf.open(m_filename, std::ios::in | std::ios::binary);
//     if (conf.fail()) {
//         std::cout << "Failed to load file " << m_filename << std::endl;
//     } else {
//         // Iterate through all keys, load from file
//         double param;
//         for (auto &it : keys) {
//             conf >> param;
//             m_tabMembers[it].set(param);
//         }
//     }
// }

// void ConfigFile::save_config() {
//     // Sort keys by name
//     std::vector<std::string> keys;
//     for (auto &it : m_tabMembers) {
//         keys.push_back(it.first);
//     }
//     std::sort(keys.begin(), keys.end());

//     // See if file exists, if don't, then don't load it.
//     std::ofstream conf;
//     conf.open(m_filename, std::ios::out | std::ios::binary);
//     if (conf.fail()) {
//         std::cout << "Failed to save file " << m_filename << std::endl;
//     } else {
//         // Iterate through all keys, load from file
//         double param;
//         for (auto &it : keys) {
//             param = m_tabMembers[it].get();
//             conf << param;
//         }
//     }
// }

// ConfigMember& ConfigFile::operator[](const std::string& key) {
//     return m_tabMembers[key];
// }
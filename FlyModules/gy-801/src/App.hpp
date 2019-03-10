#ifndef __APP_HPP__
#define __APP_HPP__

#include <thread>
#include <atomic>
#include <mutex>
#include <regex>
#include <L3G4200D.hpp>
#include <IHwApi.hpp>
#include <Logger.hpp>
#include <Udp.hpp>

namespace app
{

using Options = std::map<std::string, std::string>;

class Args
{
public:
    Args(const Options& pOptions);
    net::IpPort getCtrlAddr() const;

private:
    net::IpPort parseIpPort(std::string pKey, net::IpPort pDefault) const;
    const Options& mOptions;
};

class App
{
public:
    App(net::IUdpFactory& pUdpFactory, const Args& pArgs);
    int run();

private:
    int gyroLoop();

    net::IpPort mCtrlAddr;
    std::unique_ptr<net::ISocket> mCtrlSock;
    std::shared_ptr<hwapi::II2C>   mI2CGyro;
    l3g4200d::L3G4200D mGyro;
    std::thread mGyroLoop;
    uint8_t mXYZws[32*3*2];

    float mZ   = 0.0;
    float mY   = 0.0;
    float mX   = 0.0;
    std::mutex mXYZlock;
};

}
#endif //__APP_HPP__
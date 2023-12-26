#include <iostream>
#include <memory>
using namespace std;

enum class DeviceType {
    SMARTPHONE,
    LAPTOP
};

class Device {
public:
    virtual ~Device() = default;
    virtual void displayDetails() const = 0;
};

class Smartphone : public Device {
public:
    void displayDetails() const override {
        cout << "Smartphone: Model X, RAM: 8GB, Storage: 128GB\n";
    }
};

class Laptop : public Device {
public:
    void displayDetails() const override {
        cout << "Laptop: Model Y, RAM: 16GB, Storage: 512GB\n";
    }
};

class DeviceFactory {
public:
    virtual unique_ptr<Device> createDevice() const = 0;
    virtual ~DeviceFactory() = default;
};

class SmartphoneFactory : public DeviceFactory {
public:
    unique_ptr<Device> createDevice() const override {
        return make_unique<Smartphone>();
    }
};

class LaptopFactory : public DeviceFactory {
public:
    unique_ptr<Device> createDevice() const override {
        return make_unique<Laptop>();
    }
};

int main() {
    unique_ptr<DeviceFactory> smartphoneFactory = make_unique<SmartphoneFactory>();
    unique_ptr<DeviceFactory> laptopFactory = make_unique<LaptopFactory>();

    unique_ptr<Device> smartphoneDevice = smartphoneFactory->createDevice();
    unique_ptr<Device> laptopDevice = laptopFactory->createDevice();

    smartphoneDevice->displayDetails();
    laptopDevice->displayDetails();

    return 0;
}

#include <iostream>
#include <memory>
#include <string_view>

class UartInterface
{
public:
	UartInterface() = default;
	virtual void sendByUart(std::string_view t_text) = 0;
	virtual void receiveByUart(std::string_view t_text) = 0;
	virtual void connectDevice(UartInterface *t_device) = 0;
	virtual ~UartInterface() = default;
};

class Microcontroller : public UartInterface
{
	UartInterface *m_uartDevice;
public:
	virtual void sendByUart(std::string_view t_text) override
	{
		m_uartDevice->receiveByUart(t_text);
	}

	virtual void receiveByUart(std::string_view t_text) override
	{
		std::cout << "Received by microcontroller: " << t_text << '\n';
	}

	virtual void connectDevice(UartInterface* t_device) override
	{
		m_uartDevice = t_device;
	}
};


class UsbInterface
{
public:
	UsbInterface() = default;
	virtual void sendByUsb(std::string_view t_text) = 0;
	virtual void receiveByUsb(std::string_view t_text) = 0;
	virtual void connectDevice(UsbInterface* t_device) = 0;
	virtual ~UsbInterface() = default;
};

class Computer : public UsbInterface
{
	UsbInterface *m_usbDevice;
public:
	virtual void sendByUsb(std::string_view t_text) override
	{
		m_usbDevice->receiveByUsb(t_text);
	}

	virtual void receiveByUsb(std::string_view t_text) override
	{
		std::cout << "Received By USB: " << t_text << '\n';
	}

	virtual void connectDevice(UsbInterface* t_device) override
	{
		m_usbDevice = t_device;
	}
};


class UsbUartAdapter : public UartInterface
{
	UsbInterface* m_usbDevice;
public:
	virtual void sendByUart(std::string_view t_text) override
	{
		m_usbDevice->receiveByUsb(t_text);
	}
	virtual void receiveByUart(std::string_view t_text) override
	{
		m_usbDevice->receiveByUsb(t_text);
	}
	virtual void connectDevice(UartInterface* t_device) override{}

	void connectUsbDevice(UsbInterface* t_device)
	{
		m_usbDevice = t_device;
	}
};

int main()
{
	UartInterface* microcontroller = new Microcontroller;
	UsbInterface* laptop = new Computer;
	UartInterface* adapter = new UsbUartAdapter;

	UsbUartAdapter* tmpAdapter = dynamic_cast<UsbUartAdapter*>(adapter);
	if (tmpAdapter)
		tmpAdapter->connectUsbDevice(laptop);

	microcontroller->connectDevice(adapter);
	microcontroller->sendByUart("Hello World!");

	delete microcontroller;
	delete laptop;
	delete adapter;

	return 0;
}

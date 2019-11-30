#pragma once

#include "Shared/Shared.hpp"
#include "Shared/Singleton.hpp"
#include "Shared/SignalSlot.hpp"
#include "Shared/Lockable.h"
#include <functional>
#include <concurrent_queue.h>
#include "Shared/ServerMessage.h"
#include "Shared/ClientMessage.h"

class UKSF : public Singleton<UKSF>, public Lockable {
public:
    UKSF();
	~UKSF();

	void initialize();
	void start();
	void stop();

	Signal<void()> preStart;
    Signal<void()> postStart;
    Signal<void()> preInit;
    Signal<void()> postInit;
    Signal<void()> onFrame;
    Signal<void()> missionEnded;
	Signal<void()> threadTick;

	[[nodiscard]] STATE getState() const;

	void addToGameFunctionQueue(std::function<void()> function);
	void addToFunctionQueue(std::function<void()> function);
	void addToSendQueue(ServerMessage message);
	void addToReceiveQueue(ClientMessage message);

	std::string name;
	std::string port;
	bool isClient = false;
	bool isDedicated = false;
	bool masterThreadRun = false;

private:
	STATE m_state = STATE::STOPPED;
	bool m_stopRequested = false;
	std::thread m_workerThread;
	Concurrency::concurrent_queue<std::function<void()>> m_gameFunctionQueue{};
	Concurrency::concurrent_queue<std::function<void()>> m_functionQueue{};
	Concurrency::concurrent_queue<ServerMessage> m_sendQueue{};
	Concurrency::concurrent_queue<ClientMessage> m_receiveQueue{};

	std::string getUrlString();
	void setNewState(STATE state);
	void clearQueues();
	void doWork();
};

#pragma once

namespace nmh {

	class ManagerFactory;

	class Manager {
	protected:
		ManagerFactory* Managers;
	public:
		Manager(ManagerFactory* managerFactory) { Managers = managerFactory; }
		virtual ~Manager() { Managers = 0; }
	};
}


#include <iostream>

using namespace std;

class BaseEvent
{
private:
	string name_;

public:
	BaseEvent() : name_("") { printf("BaseEvent default constructor\n"); }
	BaseEvent(string n) : name_(n) { printf("BaseEvent name constructor\n"); }

	string getName() { return name_; }
};

class SubEvent : public BaseEvent
{
private:
	string uuid_;

public:
	SubEvent() : uuid_("") { printf("SubEvent default constructor\n"); }
	SubEvent(string name, string uuid) : BaseEvent(name), uuid_(uuid) { printf("SubEvent name, uuid constructor\n"); }

	string getUUID() { return uuid_; }
};

template<typename E>
class Maker
{
private:
	E* event_;

public:
	Maker() : event_(nullptr) { }
	~Maker() { if (event_) delete event_; }

	template<typename... Args>
	void test(Args... args)
	{
		if (event_)
			delete event_;
		event_ = new E(std::forward<Args>(args)...);
	}
};


int main(int argc, char** argv)
{
	SubEvent event("gear", "123"), ev2;

	Maker<SubEvent> maker;
	maker.test("doing it", "321");

	return 0;
}

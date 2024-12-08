#pragma once

class Airport {  };

class Airplane
{
public:
	virtual void fly(const Airport& destination) = 0;
};

class oldModel :public Airplane
{  };

class newAirplane
{
public:
	virtual void fly(const Airport& destination) = 0;
	//protected:
	//	void defaultFly(const Airport& destination) {  }
};

class ModelA : public newAirplane
{
public:
	virtual void fly(const Airport& destination) override
	{
		newAirplane::fly(destination);
	}
};

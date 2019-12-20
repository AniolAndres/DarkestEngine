#ifndef MODULE_H
#define MODULE_H

class Module
{
public:
	Module() {};
	virtual ~Module() {};

	virtual bool Init() { return true; }

	virtual bool PreUpdate() { return true; }
	virtual bool Update() { return true; }

	virtual bool CleanUp() { return true; }

};

#endif // MODULE_H
#pragma once

#ifdef PHOTOROBOTAF_EXPORTS
#define PR_API __declspec(dllexport)
#else
#define PR_API __declspec(dllimport)
#endif

class Eyes {
public:
    virtual ~Eyes() = default;
    virtual const char* draw() const = 0;
};

class Nose {
public:
    virtual ~Nose() = default;
    virtual const char* draw() const = 0;
};

class Mouth {
public:
    virtual ~Mouth() = default;
    virtual const char* draw() const = 0;
};

class PhotoRobotFactory {
public:
    virtual ~PhotoRobotFactory() = default;

    virtual Eyes* createEyes() = 0;
    virtual Nose* createNose() = 0;
    virtual Mouth* createMouth() = 0;
};

// Створення фабрики всередині DLL
extern "C" {
    PR_API PhotoRobotFactory* CreateMaleFactory();
    PR_API PhotoRobotFactory* CreateFemaleFactory();

    PR_API void DestroyFactory(PhotoRobotFactory* factory);

    PR_API void DestroyEyes(Eyes* p);
    PR_API void DestroyNose(Nose* p);
    PR_API void DestroyMouth(Mouth* p);
}
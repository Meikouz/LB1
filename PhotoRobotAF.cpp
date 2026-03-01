#define PHOTOROBOTAF_EXPORTS
#include "pch.h"
#include "PhotoRobotAF.h"

class MaleEyes : public Eyes {
public:
    const char* draw() const override { return "Чоловiчi очi"; }
};

class FemaleEyes : public Eyes {
public:
    const char* draw() const override { return "Жiночi очi"; }
};

class MaleNose : public Nose {
public:
    const char* draw() const override { return "Чоловiчий нiс"; }
};

class FemaleNose : public Nose {
public:
    const char* draw() const override { return "Жiночий нiс"; }
};

class MaleMouth : public Mouth {
public:
    const char* draw() const override { return "Чоловiчий рот"; }
};

class FemaleMouth : public Mouth {
public:
    const char* draw() const override { return "Жiночий рот"; }
};

class MaleFactory : public PhotoRobotFactory {
public:
    Eyes* createEyes() override { return new MaleEyes(); }
    Nose* createNose() override { return new MaleNose(); }
    Mouth* createMouth() override { return new MaleMouth(); }
};

class FemaleFactory : public PhotoRobotFactory {
public:
    Eyes* createEyes() override { return new FemaleEyes(); }
    Nose* createNose() override { return new FemaleNose(); }
    Mouth* createMouth() override { return new FemaleMouth(); }
};

extern "C" {

    PR_API PhotoRobotFactory* CreateMaleFactory() {
        return new MaleFactory();
    }

    PR_API PhotoRobotFactory* CreateFemaleFactory() {
        return new FemaleFactory();
    }

    PR_API void DestroyFactory(PhotoRobotFactory* factory) {
        delete factory;
    }

    PR_API void DestroyEyes(Eyes* p) { delete p; }
    PR_API void DestroyNose(Nose* p) { delete p; }
    PR_API void DestroyMouth(Mouth* p) { delete p; }

}
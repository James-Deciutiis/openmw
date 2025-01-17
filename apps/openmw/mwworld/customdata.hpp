#ifndef GAME_MWWORLD_CUSTOMDATA_H
#define GAME_MWWORLD_CUSTOMDATA_H

#include <memory>

namespace MWClass
{
    class CreatureCustomData;
    class NpcCustomData;
    class ContainerCustomData;
    class DoorCustomData;
    class CreatureLevListCustomData;
}

namespace MWWorld
{
    /// \brief Base class for the MW-class-specific part of RefData
    class CustomData
    {
    public:
        virtual ~CustomData() {}

        virtual std::unique_ptr<CustomData> clone() const = 0;

        // Fast version of dynamic_cast<X&>. Needs to be overridden in the respective class.

        virtual MWClass::CreatureCustomData& asCreatureCustomData();
        virtual const MWClass::CreatureCustomData& asCreatureCustomData() const;

        virtual MWClass::NpcCustomData& asNpcCustomData();
        virtual const MWClass::NpcCustomData& asNpcCustomData() const;

        virtual MWClass::ContainerCustomData& asContainerCustomData();
        virtual const MWClass::ContainerCustomData& asContainerCustomData() const;

        virtual MWClass::DoorCustomData& asDoorCustomData();
        virtual const MWClass::DoorCustomData& asDoorCustomData() const;

        virtual MWClass::CreatureLevListCustomData& asCreatureLevListCustomData();
        virtual const MWClass::CreatureLevListCustomData& asCreatureLevListCustomData() const;
    };

    template <class T>
    struct TypedCustomData : CustomData
    {
        std::unique_ptr<CustomData> clone() const final { return std::make_unique<T>(*static_cast<const T*>(this)); }
    };
}

#endif

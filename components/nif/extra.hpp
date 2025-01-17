/*
  OpenMW - The completely unofficial reimplementation of Morrowind
  Copyright (C) 2008-2010  Nicolay Korslund
  Email: < korslund@gmail.com >
  WWW: https://openmw.org/

  This file (extra.h) is part of the OpenMW package.

  OpenMW is distributed as free software: you can redistribute it
  and/or modify it under the terms of the GNU General Public License
  version 3, as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  version 3 along with this program. If not, see
  https://www.gnu.org/licenses/ .

 */

#ifndef OPENMW_COMPONENTS_NIF_EXTRA_HPP
#define OPENMW_COMPONENTS_NIF_EXTRA_HPP

#include "base.hpp"

namespace Nif
{

    struct NiExtraData : public Extra
    {
        std::vector<char> data;

        void read(NIFStream* nif) override;
    };

    struct NiVertWeightsExtraData : public Extra
    {
        void read(NIFStream* nif) override;
    };

    struct NiTextKeyExtraData : public Extra
    {
        struct TextKey
        {
            float time;
            std::string text;
        };
        std::vector<TextKey> list;

        void read(NIFStream* nif) override;
    };

    struct NiStringExtraData : public Extra
    {
        /* Known meanings:
           "MRK" - marker, only visible in the editor, not rendered in-game
           "NCC" - no collision except with the camera
           Anything else starting with "NC" - no collision
        */
        std::string string;

        void read(NIFStream* nif) override;
    };

    struct NiIntegerExtraData : public Extra
    {
        unsigned int data;

        void read(NIFStream* nif) override;
    };

    struct NiIntegersExtraData : public Extra
    {
        std::vector<unsigned int> data;

        void read(NIFStream* nif) override;
    };

    struct NiBinaryExtraData : public Extra
    {
        std::vector<char> data;

        void read(NIFStream* nif) override;
    };

    struct NiBooleanExtraData : public Extra
    {
        bool data;

        void read(NIFStream* nif) override;
    };

    struct NiVectorExtraData : public Extra
    {
        osg::Vec4f data;

        void read(NIFStream* nif) override;
    };

    struct NiFloatExtraData : public Extra
    {
        float data;

        void read(NIFStream* nif) override;
    };

    struct NiFloatsExtraData : public Extra
    {
        std::vector<float> data;

        void read(NIFStream* nif) override;
    };

    struct BSBound : public Extra
    {
        osg::Vec3f center, halfExtents;

        void read(NIFStream* nif) override;
    };

    struct BSFurnitureMarker : public Extra
    {
        struct LegacyFurniturePosition
        {
            osg::Vec3f mOffset;
            uint16_t mOrientation;
            uint8_t mPositionRef;
            void read(NIFStream* nif);
        };

        struct FurniturePosition
        {
            osg::Vec3f mOffset;
            float mHeading;
            uint16_t mType;
            uint16_t mEntryPoint;
            void read(NIFStream* nif);
        };

        std::vector<LegacyFurniturePosition> mLegacyMarkers;
        std::vector<FurniturePosition> mMarkers;

        void read(NIFStream* nif) override;
    };

} // Namespace
#endif

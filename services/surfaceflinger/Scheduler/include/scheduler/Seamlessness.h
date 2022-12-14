/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <ostream>

#include <ftl/enum.h>

namespace android::scheduler {

// The seamlessness requirement of a Layer.
enum class Seamlessness {
    // Indicates a requirement for a seamless mode switch.
    OnlySeamless,
    // Indicates that both seamless and seamed mode switches are allowed.
    SeamedAndSeamless,
    // Indicates no preference for seamlessness. For such layers the system will
    // prefer seamless switches, but also non-seamless switches to the group of the
    // default config are allowed.
    Default,

    ftl_last = Default
};

// Used by gtest
inline std::ostream& operator<<(std::ostream& os, Seamlessness s) {
    return os << ftl::enum_string(s);
}

} // namespace android::scheduler

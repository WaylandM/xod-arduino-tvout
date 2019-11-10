// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/WaylandM/MTW-arduino-tvout"

//Include C++ libraries
{{#global}}
#include <TVout.h>
#include <fontALL.h>
{{/global}}

// Reserve memory to store an instance of the TVout class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(TVout)];
};

// Define our custom type as a pointer on the class instance.
using Type = TVout*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type tv = new (state->mem) TVout();

    emitValue<output_DEV>(ctx, tv);
}

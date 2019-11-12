
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);
    char color = getValue<input_COLOR>(ctx);

    tv->fill(color);

    emitValue<output_DONE>(ctx, 1);
}

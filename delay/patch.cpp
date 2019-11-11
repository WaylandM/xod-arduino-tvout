
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);
    unsigned int t = getValue<input_T>(ctx);

    tv->delay(t);

    emitValue<output_DONE>(ctx, 1);
}

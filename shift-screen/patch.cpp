
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);
    uint8_t dir, dist;
    dir = getValue<input_DIR>(ctx);
    dist = getValue<input_DIST>(ctx);

    tv->shift(dist, dir);

    emitValue<output_DONE>(ctx, 1);
}

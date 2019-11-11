
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);
    uint8_t x = getValue<input_X>(ctx);
    uint8_t y = getValue<input_Y>(ctx);
    uint8_t r = getValue<input_R>(ctx);
    char color = getValue<input_COLOR>(ctx);
    char fill = getValue<input_FILL>(ctx);

    tv->draw_circle(x, y, r, color, fill);

    emitValue<output_DONE>(ctx, 1);
}

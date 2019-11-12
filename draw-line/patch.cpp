
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);
    uint8_t x0 = getValue<input_X0>(ctx);
    uint8_t y0 = getValue<input_Y0>(ctx);
    uint8_t x1 = getValue<input_X1>(ctx);
    uint8_t y1 = getValue<input_Y1>(ctx);
    char color = getValue<input_COLOR>(ctx);

    tv->draw_line(x0, y0, x1, y1, color);

    emitValue<output_DONE>(ctx, 1);
}

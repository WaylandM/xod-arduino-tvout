
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);
    uint16_t x0 = getValue<input_X0>(ctx);
    uint16_t x1 = getValue<input_X1>(ctx);
    uint8_t column = getValue<input_COLUMN>(ctx);
    char color = getValue<input_COLOR>(ctx);

    tv->draw_column(column, x0, x1, color);

    emitValue<output_DONE>(ctx, 1);
}


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
    uint8_t w = getValue<input_W>(ctx);
    uint8_t h = getValue<input_H>(ctx);
    char color = getValue<input_COLOR>(ctx);
    char fill = getValue<input_FILL>(ctx);


    tv->select_font(font4x6);
    tv->select_font(font6x8);
    tv->select_font(font8x8);
    tv->select_font(font8x8ext);
    
    tv->draw_rect(x, y, w, h, color, fill);

    emitValue<output_DONE>(ctx, 1);
}

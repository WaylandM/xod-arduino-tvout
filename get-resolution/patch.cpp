
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);

    unsigned char x, y;
    x = tv->hres();
    y = tv->vres();
    emitValue<output_X>(ctx, x);
    emitValue<output_Y>(ctx, y);
}

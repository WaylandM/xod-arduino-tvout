
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `TVout` class instance
    auto tv = getValue<input_DEV>(ctx);
    auto xString = getValue<input_TEXT>(ctx);
    auto font = getValue<input_FONT>(ctx);
    uint8_t x = getValue<input_X>(ctx);
    uint8_t y = getValue<input_Y>(ctx);
    auto xy = getValue<input_XY>(ctx);

    int N=length(xString) + 1;
    char cString[N];
    for(int i=0;i<N;i++)
    cString[i]=0;
    // move the data from XString to the plain C string
    dump(xString, cString);

    if (font==0) {
        tv->select_font(font4x6);
    }
    else if(font==1) {
        tv->select_font(font6x8);
    }
    else if(font==2) {
        tv->select_font(font8x8);
    }
    else if(font==3) {
        tv->select_font(font8x8ext);
    }
    else {
      raiseError(ctx);
      return;
    }
    
    if (xy) {
        tv->println(x, y, cString)
    } else {
        tv->println(cString)
    }

    emitValue<output_DONE>(ctx, 1);
}

module numeroCartao (
    input	botao,
    output a1,
    output b1,
    output c1,
    output d1,
    output e1,
    output f1,
    output g1,
    output a2,
    output b2,
    output c2,
    output d2,
    output e2,
    output f2,
    output g2,
    output a3,
    output b3,
    output c3,
    output d3,
    output e3,
    output f3,
    output g3
    );

    wire  nbotao, vcc, gnd;

    not(nbotao, botao);
    or(vcc, nbotao,botao);
    not(gnd, vcc);

    or(b1, nbotao, botao);
    or(c1, nbotao, botao);
    and(e1, nbotao, botao);

    mux21 mux21_var_a1(
        .sel(botao),.e1(vcc),.e0(gnd),.s(a1)
    );
    mux21 mux21_var_d1(
        .sel(botao),.e1(vcc),.e0(gnd),.s(d1)
    );
    mux21 mux21_var_f1(
        .sel(botao),.e1(vcc),.e0(gnd),.s(f1)
    );
    mux21 mux21_var_g1(
        .sel(botao),.e1(vcc),.e0(gnd),.s(g1)
    );
    
    or(a2, nbotao, botao);
    or(c2, nbotao, botao);
    or(d2, nbotao, botao);
    or(e2, nbotao, botao);
    or(f2, nbotao, botao);
    or(g2, nbotao, botao);
    
    mux21 mux21_var_b2(
        .sel(botao),.e1(vcc),.e0(gnd),.s(b2)
    );

    or(a3, nbotao, botao);
    or(b3, nbotao, botao);
    or(d3, nbotao, botao);
    or(e3, nbotao, botao);

    mux21 mux21_var_c3(
        .sel(botao),.e1(gnd),.e0(vcc),.s(c3) 
    );
    mux21 mux21_var_f3(
        .sel(botao),.e1(gnd),.e0(vcc),.s(f3)
    );
    mux21 mux21_var_g3(
        .sel(botao),.e1(vcc),.e0(gnd),.s(g3)
    );
    
endmodule

    
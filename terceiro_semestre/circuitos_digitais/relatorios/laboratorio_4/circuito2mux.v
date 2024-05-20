//circuito do slide 26 da aula de BDDs e mux
module circuito2mux (
    input	a,
    input	b,
    input	c,
    output	f);

    wire x1, nc, vcc;
    not(nc, c);

    mux21 mux21_var_a(
        .sel(a),.e1(x1),.e0(c),.s(f) 
    );
    
	mux21 mux21_var_b(
        .sel(b),.e1(vcc),.e0(nc),.s(x1) 
    );
	or(vcc, nc, c);

endmodule


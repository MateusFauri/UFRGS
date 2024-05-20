module mux21 (
    input	sel,
    input	e1,
    input	e0,
    output	s);

    wire x1, x0, nsel;

    not(nsel, sel);
    
    and(x1, e1, sel);
    and(x0, e0, nsel);
    or(s, x1, x0);

endmodule


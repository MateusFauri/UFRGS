module duas_chaves(
    input in2, //A
    input in1, //B
    input in0, //C
    output a,
    output b,
    output c,
    output d,
    output e,
    output f,
    output g
    );

wire nin2, nin1, nin0;
not(nin1, in1);
not(nin0, in0);
not(nin2, in2);

wire e1,e2;
wire f1,f2;
wire g1,g2;

//a
or(a, in2,in1,in0);

//b
or(b, nin0, in2, in1);

//c 
or(c, nin0, in1, nin2);

//d
or(d, in2, in1, in0);


//e
and(e1, in1, nin0);
and(e2, nin1, in0);
or(e, in2, e1, e2);

//f
and(f1, nin2, in0);
and(f2, in2, nin0);
or(f,f1,f2,in1);

//g
and(g1, nin2, in0);
and(g2, in2, nin1);
or(g, g1,g2);


endmodule
module reg2 (
input	[2:0] a,
input   [2:0] b,
input	subtrai,
input	[1:0] s,
output   cout,
output  [2:0] fi);

    wire  [2:0]sum;

    add ula_add(   .a(a),
                    .b(b),
                    .subtrator(subtrai),
                    .cout(cout),
                    .s(sum)
                    );

    mux41 ula_mux(  .sel(s),
                    .a(a),
                    .b(b),
                    .sum(sum),
                    .s(fi));
    

endmodule
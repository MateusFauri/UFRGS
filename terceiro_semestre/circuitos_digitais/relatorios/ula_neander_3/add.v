module add (
input	[2:0] a,
input	[2:0] b,
input   subtrator,
output	cout,
output  [2:0] s);

    wire [2:0] fiob;
    wire [1:0] fio;

    xor(fiob[0], b[0], subtrator);
    xor(fiob[1], b[1], subtrator);
    xor(fiob[2], b[2], subtrator);


    full_adder bit_0(   .a(a[0]),
                        .b(fiob[0]),
                        .cin(subtrator),
                        .s(s[0]),
                        .cout(fio[0]));

    full_adder bit_1(   .a(a[1]),
                        .b(fiob[1]),
                        .cin(fio[0]),
                        .s(s[1]),
                        .cout(fio[1]));

 
    full_adder bit_2(   .a(a[2]),
                        .b(fiob[2]),
                        .cin(fio[1]),
                        .s(s[2]),
                        .cout(cout));


endmodule


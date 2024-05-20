module mux41 (
    input	[1:0] sel,
    input   [2:0] a,
    input   [2:0] b,
    input   [2:0] sum,
    output	[2:0] s);

    wire [2:0] fio_or;
    wire [2:0] fio_a_not;
    wire [2:0] fio_and;
    wire [2:0] saida0;
    wire [2:0] saida1;
    
    or(fio_or[0], a[0], b[0]);
    or(fio_or[1], a[1], b[1]);
    or(fio_or[2], a[2], b[2]);

    and(fio_and[0], a[0], b[0]);
    and(fio_and[1], a[1], b[1]);
    and(fio_and[2], a[2], b[2]);

    not(fio_a_not[0], a[0]);
    not(fio_a_not[1], a[1]);
    not(fio_a_not[2], a[2]);


// primeiro
    mux21 mux21_var_a_0(
        .sel(sel[1]),.e1(fio_and[0]),.e0(sum[0]),.s(saida0[0]) 
    );
    
	mux21 mux21_var_b_0(
        .sel(sel[1]),.e1(fio_a_not[0]),.e0(fio_or[0]),.s(saida1[0]) 
    );

    mux21 mux_saida_0(
        .sel(sel[0]),.e1(saida1[0]),.e0(saida0[0]),.s(s[0]) 
    );

// Segundo
    mux21 mux21_var_a_1(
        .sel(sel[1]),.e1(fio_and[1]),.e0(sum[1]),.s(saida0[1]) 
    );
    
	mux21 mux21_var_b_1(
        .sel(sel[1]),.e1(fio_a_not[1]),.e0(fio_or[1]),.s(saida1[1]) 
    );

    mux21 mux_saida_1(
        .sel(sel[0]),.e1(saida1[1]),.e0(saida0[1]),.s(s[1]) 
    );

// terceiro
    mux21 mux21_var_a_2(
        .sel(sel[1]),.e1(fio_and[2]),.e0(sum[2]),.s(saida0[2]) 
    );
    
	mux21 mux21_var_b_2(
        .sel(sel[1]),.e1(fio_a_not[2]),.e0(fio_or[2]),.s(saida1[2]) 
    );

    mux21 mux_saida_2(
        .sel(sel[0]),.e1(saida1[2]),.e0(saida0[2]),.s(s[2]) 
    );


endmodule

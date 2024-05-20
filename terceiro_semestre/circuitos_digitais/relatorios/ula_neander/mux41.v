module mux41 (
    input	[1:0] sel,
    input   [7:0] a,
    input   [7:0] b,
    input   [7:0] sum,
    output	[7:0] s);

    wire [7:0] fio_or;
    wire [7:0] fio_a_not;
    wire [7:0] fio_and;
    wire [7:0] saida0;
    wire [7:0] saida1;
    
    
    or(fio_or[0], a[0], b[0]);
    or(fio_or[1], a[1], b[1]);
    or(fio_or[2], a[2], b[2]);
    or(fio_or[3], a[3], b[3]);
    or(fio_or[4], a[4], b[4]);
    or(fio_or[5], a[5], b[5]);
    or(fio_or[6], a[6], b[6]);
    or(fio_or[7], a[7], b[7]);

    and(fio_and[0], a[0], b[0]);
    and(fio_and[1], a[1], b[1]);
    and(fio_and[2], a[2], b[2]);
    and(fio_and[3], a[3], b[3]);
    and(fio_and[4], a[4], b[4]);
    and(fio_and[5], a[5], b[5]);
    and(fio_and[6], a[6], b[6]);
    and(fio_and[7], a[7], b[7]);

    not(fio_a_not[0], a[0]);
    not(fio_a_not[1], a[1]);
    not(fio_a_not[2], a[2]);
    not(fio_a_not[3], a[3]);
    not(fio_a_not[4], a[4]);
    not(fio_a_not[5], a[5]);
    not(fio_a_not[6], a[6]);
    not(fio_a_not[7], a[7]);

// primeiro
    mux21 mux21_var_a_0(
        .sel(sel[1]),.e(fio_or[0]),.e0(sum[0]),.s(saida0[0]) 
    );
    
	mux21 mux21_var_b_0(
        .sel(sel[1]),.e(fio_a_not[0]),.e0(fio_and[0]),.s(saida1[0]) 
    );

    mux21 mux_saida_0(
        .sel(sel[0]),.e(saida1[0]),.e0(saida0[0]),.s(s[0]) 
    );

// Segundo
    mux21 mux21_var_a_1(
        .sel(sel[1]),.e(fio_or[1]),.e0(sum[1]),.s(saida0[1]) 
    );
    
	mux21 mux21_var_b_1(
        .sel(sel[1]),.e(fio_a_not[1]),.e0(fio_and[1]),.s(saida1[1]) 
    );

    mux21 mux_saida_1(
        .sel(sel[0]),.e(saida1[1]),.e0(saida0[1]),.s(s[1]) 
    );

// terceiro
    mux21 mux21_var_a_2(
        .sel(sel[1]),.e(fio_or[2]),.e0(sum[2]),.s(saida0[2]) 
    );
    
	mux21 mux21_var_b_2(
        .sel(sel[1]),.e(fio_a_not[2]),.e0(fio_and[2]),.s(saida1[2]) 
    );

    mux21 mux_saida_2(
        .sel(sel[0]),.e(saida1[2]),.e0(saida0[2]),.s(s[2]) 
    );

// quarto
    mux21 mux21_var_a_3(
        .sel(sel[1]),.e(fio_or[3]),.e0(sum[3]),.s(saida0[3]) 
    );
    
	mux21 mux21_var_b_3(
        .sel(sel[1]),.e(fio_a_not[3]),.e0(fio_and[3]),.s(saida1[3]) 
    );

    mux21 mux_saida_3(
        .sel(sel[0]),.e(saida1[3]),.e0(saida0[3]),.s(s[3]) 
    );

// quinto
    mux21 mux21_var_a_4(
        .sel(sel[1]),.e(fio_or[4]),.e0(sum[4]),.s(saida0[4]) 
    );
    
	mux21 mux21_var_b_4(
        .sel(sel[1]),.e(fio_a_not[4]),.e0(fio_and[4]),.s(saida1[4]) 
    );

    mux21 mux_saida_4(
        .sel(sel[0]),.e(saida1[4]),.e0(saida0[4]),.s(s[4]) 
    );
        

// sexto
    mux21 mux21_var_a_5(
        .sel(sel[1]),.e(fio_or[5]),.e0(sum[5]),.s(saida0[5]) 
    );
    
	mux21 mux21_var_b_5(
        .sel(sel[1]),.e(fio_a_not[5]),.e0(fio_and[5]),.s(saida1[5]) 
    );

    mux21 mux_saida_5(
        .sel(sel[0]),.e(saida1[5]),.e0(saida0[5]),.s(s[5]) 
    );
        
// setimo    
    mux21 mux21_var_a_6(
        .sel(sel[1]),.e(fio_or[6]),.e0(sum[6]),.s(saida0[6]) 
    );
    
	mux21 mux21_var_b_6(
        .sel(sel[1]),.e(fio_a_not[6]),.e0(fio_and[6]),.s(saida1[6]) 
    );

    mux21 mux_saida_6(
        .sel(sel[0]),.e(saida1[6]),.e0(saida0[6]),.s(s[6]) 
    );
        
// oitavo
    mux21 mux21_var_a_7(
        .sel(sel[1]),.e(fio_or[7]),.e0(sum[7]),.s(saida0[7]) 
    );
    
	mux21 mux21_var_b_7(
        .sel(sel[1]),.e(fio_a_not[7]),.e0(fio_and[7]),.s(saida1[7]) 
    );

    mux21 mux_saida_7(
        .sel(sel[0]),.e(saida1[7]),.e0(saida0[7]),.s(s[7]) 
    );
    

endmodule

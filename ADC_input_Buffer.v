
module ADC_Input_Buffer(
    input clk,
    input rstn,
    input [11:0] data_p_in,
    input [11:0] data_n_in,
    input clk_p_in,
    input clk_n_in,
    output clk_112M,
    output [95:0] data_out
    );
wire [11:0] data_in;

genvar var_k;
generate
    for (var_k = 0; var_k < 12; var_k = var_k + 1 )
    begin
    IBUFDS
      #(.DIFF_TERM  ("FALSE"),             // Differential termination
        .IOSTANDARD ("LVDS"))
     ibufds_inst
       (.I          (data_p_in  [var_k]),
        .IB         (data_n_in  [var_k]),
        .O          (data_in [var_k]));
        end
endgenerate

IBUFDS
      #(.DIFF_TERM  ("FALSE"),             // Differential termination
        .IOSTANDARD ("LVDS"))
     ibufds_inst0
       (.I          (clk_),
        .IB         (data_n_in  [var_k]),
        .O          (data_in [var_k]));



endmodule
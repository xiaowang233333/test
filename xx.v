module spi_master(
    input clk,
    input rstn,
    input [7:0] address_in,
    input [15:0] cfg_data_in,
    output [15:0] rb_data_out,
    input cfg_enable_in,
    output cfg_done_out
)

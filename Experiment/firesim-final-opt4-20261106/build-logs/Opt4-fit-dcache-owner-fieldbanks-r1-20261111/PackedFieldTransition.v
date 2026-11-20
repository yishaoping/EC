module PackedFieldTransition(
input reset, written, write_enable, selected,
input [145:0] previous_raw, write_data,
output equivalent, mutation_equivalent);
wire write = write_enable && !reset && selected;
wire mask_next = !reset && (written || write);
wire [145:0] packed_next = write ? write_data : previous_raw;
wire [80:0] image_next = write ? write_data[145:65] : previous_raw[145:65];
wire [31:0] generation_next = write ? write_data[64:33] : previous_raw[64:33];
wire [31:0] packet_next = write ? write_data[32:1] : previous_raw[32:1];
wire tracked_next = write ? write_data[0] : previous_raw[0];
wire [145:0] field_next = {image_next,generation_next,packet_next,tracked_next};
wire [145:0] packed_observed = mask_next ? packed_next : 146'h0;
wire [145:0] field_observed = mask_next ? field_next : 146'h0;
// Real candidate field-data corruption, with no change to proof predicate.
wire [145:0] mutated_field_next = {image_next,generation_next,packet_next,write ? !write_data[0] : previous_raw[0]};
assign equivalent = packed_observed == field_observed;
assign mutation_equivalent = packed_observed == (mask_next ? mutated_field_next : 146'h0);
endmodule

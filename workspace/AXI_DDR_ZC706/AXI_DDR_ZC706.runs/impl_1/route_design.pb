
Q
Command: %s
53*	vivadotcl2 
route_design2default:defaultZ4-113h px? 
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2"
Implementation2default:default2
xc7z0452default:defaultZ17-347h px? 
?
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
xc7z0452default:defaultZ17-349h px? 
?
?The version limit for your license is '%s' and will not allow you to run Xilinx software released after that date (year & month). A version limit expiration means that while you will be able to continue to use the current version of tools or IP with this license, you will not be able to use any updates or new releases.
784*common2
2021.082default:defaultZ17-1686h px? 
p
,Running DRC as a precondition to command %s
22*	vivadotcl2 
route_design2default:defaultZ4-22h px? 
P
Running DRC with %s threads
24*drc2
22default:defaultZ23-27h px? 
?
?Clock Placer Checks: Sub-optimal placement for a clock-capable IO pin and MMCM pair. 
Resolution: A dedicated routing path between the two can be used if: (a) The clock-capable IO (CCIO) is placed on a CCIO capable site (b) The MMCM is placed in the same clock region as the CCIO pin. If the IOB is driving multiple MMCMs, all MMCMs must be placed in the same clock region, one clock region above or one clock region below the IOB. Both the above conditions must be met at the same time, else it may lead to longer and less predictable clock insertion delays.
 This is normally an ERROR but the CLOCK_DEDICATED_ROUTE constraint is set to FALSE allowing your design to continue. The use of this override is highly discouraged as it may lead to very poor timing results. It is recommended that this error condition be corrected in the design.

	%s (IBUFDS.O) is locked to %s
	%s (MMCME2_ADV.CLKIN1) is provisionally placed by clockplacer on %s
%s*DRC2?
 "?
hdesign_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_ddr3_clk_ibuf/diff_input_clk.u_ibufg_sys_clk	hdesign_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_ddr3_clk_ibuf/diff_input_clk.u_ibufg_sys_clk2default:default2default:default2B
 ",

IOB_X1Y274

IOB_X1Y2742default:default2default:default2?
 "?
`design_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_iodelay_ctrl/clk_ref_mmcm_gen.mmcm_i	`design_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_iodelay_ctrl/clk_ref_mmcm_gen.mmcm_i2default:default2default:default2L
 "6
MMCME2_ADV_X0Y0
MMCME2_ADV_X0Y02default:default2default:default2;
 #DRC|Implementation|Placement|Clocks2default:default8ZPLCK-23h px? 
b
DRC finished with %s
79*	vivadotcl2(
0 Errors, 1 Warnings2default:defaultZ4-198h px? 
e
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px? 
V

Starting %s Task
103*constraints2
Routing2default:defaultZ18-103h px? 
}
BMultithreading enabled for route_design using a maximum of %s CPUs17*	routeflow2
22default:defaultZ35-254h px? 
p

Phase %s%s
101*constraints2
1 2default:default2#
Build RT Design2default:defaultZ18-101h px? 
B
-Phase 1 Build RT Design | Checksum: 8b45d1b1
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:01:45 ; elapsed = 00:01:06 . Memory (MB): peak = 2893.836 ; gain = 229.5002default:defaulth px? 
v

Phase %s%s
101*constraints2
2 2default:default2)
Router Initialization2default:defaultZ18-101h px? 
o

Phase %s%s
101*constraints2
2.1 2default:default2 
Create Timer2default:defaultZ18-101h px? 
A
,Phase 2.1 Create Timer | Checksum: 8b45d1b1
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:01:45 ; elapsed = 00:01:07 . Memory (MB): peak = 2893.836 ; gain = 229.5002default:defaulth px? 
{

Phase %s%s
101*constraints2
2.2 2default:default2,
Fix Topology Constraints2default:defaultZ18-101h px? 
M
8Phase 2.2 Fix Topology Constraints | Checksum: 8b45d1b1
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:01:45 ; elapsed = 00:01:07 . Memory (MB): peak = 2900.078 ; gain = 235.7422default:defaulth px? 
t

Phase %s%s
101*constraints2
2.3 2default:default2%
Pre Route Cleanup2default:defaultZ18-101h px? 
F
1Phase 2.3 Pre Route Cleanup | Checksum: 8b45d1b1
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:01:45 ; elapsed = 00:01:07 . Memory (MB): peak = 2900.078 ; gain = 235.7422default:defaulth px? 
p

Phase %s%s
101*constraints2
2.4 2default:default2!
Update Timing2default:defaultZ18-101h px? 
C
.Phase 2.4 Update Timing | Checksum: 20ecd2f3e
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:04 ; elapsed = 00:01:21 . Memory (MB): peak = 2981.680 ; gain = 317.3442default:defaulth px? 
?
Intermediate Timing Summary %s164*route2L
8| WNS=0.119  | TNS=0.000  | WHS=-0.473 | THS=-1998.292|
2default:defaultZ35-416h px? 
I
4Phase 2 Router Initialization | Checksum: 1f0bc0fc8
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:12 ; elapsed = 00:01:26 . Memory (MB): peak = 2981.680 ; gain = 317.3442default:defaulth px? 
p

Phase %s%s
101*constraints2
3 2default:default2#
Initial Routing2default:defaultZ18-101h px? 
C
.Phase 3 Initial Routing | Checksum: 1c63047d0
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:19 ; elapsed = 00:01:30 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
?
>Design has %s pins with tight setup and hold constraints.

%s
244*route2
1032default:default2?
?The top 5 pins with tight setup and hold constraints:

+--------------------------+--------------------------+----------------------------------------------------------------------------------------------------------+
|       Launch Clock       |      Capture Clock       |                                                 Pin                                                      |
+--------------------------+--------------------------+----------------------------------------------------------------------------------------------------------+
|            oserdes_clk_8 |         oserdes_clkdiv_8 |design_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_2.u_ddr_phy_4lanes/ddr_byte_lane_B.ddr_byte_lane_B/ddr_byte_group_io/output_[8].oserdes_dq_.ddr.oserdes_dq_i/RST|
|            oserdes_clk_1 |         oserdes_clkdiv_1 |design_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_0.u_ddr_phy_4lanes/ddr_byte_lane_B.ddr_byte_lane_B/ddr_byte_group_io/output_[8].oserdes_dq_.ddr.oserdes_dq_i/RST|
|            oserdes_clk_9 |         oserdes_clkdiv_9 |design_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_2.u_ddr_phy_4lanes/ddr_byte_lane_C.ddr_byte_lane_C/ddr_byte_group_io/output_[2].oserdes_dq_.ddr.oserdes_dq_i/RST|
|            oserdes_clk_2 |         oserdes_clkdiv_2 |design_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_0.u_ddr_phy_4lanes/ddr_byte_lane_C.ddr_byte_lane_C/ddr_byte_group_io/output_[2].oserdes_dq_.ddr.oserdes_dq_i/RST|
|            oserdes_clk_4 |         oserdes_clkdiv_4 |design_v3_i/mig_7series_0/u_design_v3_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_1.u_ddr_phy_4lanes/ddr_byte_lane_B.ddr_byte_lane_B/ddr_byte_group_io/output_[6].oserdes_dq_.sdr.oserdes_dq_i/RST|
+--------------------------+--------------------------+----------------------------------------------------------------------------------------------------------+

File with complete list of pins: tight_setup_hold_pins.txt
2default:defaultZ35-580h px? 
s

Phase %s%s
101*constraints2
4 2default:default2&
Rip-up And Reroute2default:defaultZ18-101h px? 
u

Phase %s%s
101*constraints2
4.1 2default:default2&
Global Iteration 02default:defaultZ18-101h px? 
?
Intermediate Timing Summary %s164*route2J
6| WNS=0.106  | TNS=0.000  | WHS=N/A    | THS=N/A    |
2default:defaultZ35-416h px? 
H
3Phase 4.1 Global Iteration 0 | Checksum: 126d2da81
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:41 ; elapsed = 00:01:44 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
F
1Phase 4 Rip-up And Reroute | Checksum: 126d2da81
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:41 ; elapsed = 00:01:44 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
|

Phase %s%s
101*constraints2
5 2default:default2/
Delay and Skew Optimization2default:defaultZ18-101h px? 
p

Phase %s%s
101*constraints2
5.1 2default:default2!
Delay CleanUp2default:defaultZ18-101h px? 
C
.Phase 5.1 Delay CleanUp | Checksum: 126d2da81
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:41 ; elapsed = 00:01:44 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
z

Phase %s%s
101*constraints2
5.2 2default:default2+
Clock Skew Optimization2default:defaultZ18-101h px? 
M
8Phase 5.2 Clock Skew Optimization | Checksum: 126d2da81
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:41 ; elapsed = 00:01:44 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
O
:Phase 5 Delay and Skew Optimization | Checksum: 126d2da81
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:42 ; elapsed = 00:01:44 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
n

Phase %s%s
101*constraints2
6 2default:default2!
Post Hold Fix2default:defaultZ18-101h px? 
p

Phase %s%s
101*constraints2
6.1 2default:default2!
Hold Fix Iter2default:defaultZ18-101h px? 
r

Phase %s%s
101*constraints2
6.1.1 2default:default2!
Update Timing2default:defaultZ18-101h px? 
D
/Phase 6.1.1 Update Timing | Checksum: af89e699
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:45 ; elapsed = 00:01:47 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
?
Intermediate Timing Summary %s164*route2J
6| WNS=0.106  | TNS=0.000  | WHS=0.011  | THS=0.000  |
2default:defaultZ35-416h px? 
C
.Phase 6.1 Hold Fix Iter | Checksum: 1136ea9d3
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:45 ; elapsed = 00:01:47 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
A
,Phase 6 Post Hold Fix | Checksum: 1136ea9d3
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:45 ; elapsed = 00:01:47 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
o

Phase %s%s
101*constraints2
7 2default:default2"
Route finalize2default:defaultZ18-101h px? 
B
-Phase 7 Route finalize | Checksum: 15a3296a1
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:46 ; elapsed = 00:01:47 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
v

Phase %s%s
101*constraints2
8 2default:default2)
Verifying routed nets2default:defaultZ18-101h px? 
I
4Phase 8 Verifying routed nets | Checksum: 15a3296a1
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:46 ; elapsed = 00:01:47 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
r

Phase %s%s
101*constraints2
9 2default:default2%
Depositing Routes2default:defaultZ18-101h px? 
E
0Phase 9 Depositing Routes | Checksum: 1a1f402d5
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:48 ; elapsed = 00:01:51 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
t

Phase %s%s
101*constraints2
10 2default:default2&
Post Router Timing2default:defaultZ18-101h px? 
?
Estimated Timing Summary %s
57*route2J
6| WNS=0.106  | TNS=0.000  | WHS=0.011  | THS=0.000  |
2default:defaultZ35-57h px? 
?
?The final timing numbers are based on the router estimated timing analysis. For a complete and accurate timing signoff, please run report_timing_summary.
127*routeZ35-327h px? 
G
2Phase 10 Post Router Timing | Checksum: 1a1f402d5
*commonh px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:49 ; elapsed = 00:01:51 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
@
Router Completed Successfully
2*	routeflowZ35-16h px? 
?

%s
*constraints2q
]Time (s): cpu = 00:02:49 ; elapsed = 00:01:51 . Memory (MB): peak = 2984.668 ; gain = 320.3322default:defaulth px? 
Z
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
1432default:default2
252default:default2
102default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
route_design2default:defaultZ4-42h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2"
route_design: 2default:default2
00:02:552default:default2
00:01:572default:default2
2984.6682default:default2
327.0472default:defaultZ17-268h px? 
H
&Writing timing data to binary archive.266*timingZ38-480h px? 
D
Writing placer database...
1603*designutilsZ20-1893h px? 
=
Writing XDEF routing.
211*designutilsZ20-211h px? 
J
#Writing XDEF routing logical nets.
209*designutilsZ20-209h px? 
J
#Writing XDEF routing special nets.
210*designutilsZ20-210h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2)
Write XDEF Complete: 2default:default2
00:00:092default:default2
00:00:032default:default2
2984.6682default:default2
0.0002default:defaultZ17-268h px? 
?
 The %s '%s' has been generated.
621*common2

checkpoint2default:default2?
?C:/Users/Projet/Desktop/Recherche/gallay_DDR_ZC706/workspace/AXI_DDR_ZC706/AXI_DDR_ZC706.runs/impl_1/design_v3_wrapper_routed.dcp2default:defaultZ17-1381h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2&
write_checkpoint: 2default:default2
00:00:162default:default2
00:00:102default:default2
2984.6682default:default2
0.0002default:defaultZ17-268h px? 
?
%s4*runtcl2?
?Executing : report_drc -file design_v3_wrapper_drc_routed.rpt -pb design_v3_wrapper_drc_routed.pb -rpx design_v3_wrapper_drc_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
{report_drc -file design_v3_wrapper_drc_routed.rpt -pb design_v3_wrapper_drc_routed.pb -rpx design_v3_wrapper_drc_routed.rpx2default:defaultZ4-113h px? 
>
IP Catalog is up to date.1232*coregenZ19-1839h px? 
P
Running DRC with %s threads
24*drc2
22default:defaultZ23-27h px? 
?
#The results of DRC are in file %s.
168*coretcl2?
?C:/Users/Projet/Desktop/Recherche/gallay_DDR_ZC706/workspace/AXI_DDR_ZC706/AXI_DDR_ZC706.runs/impl_1/design_v3_wrapper_drc_routed.rpt?C:/Users/Projet/Desktop/Recherche/gallay_DDR_ZC706/workspace/AXI_DDR_ZC706/AXI_DDR_ZC706.runs/impl_1/design_v3_wrapper_drc_routed.rpt2default:default8Z2-168h px? 
\
%s completed successfully
29*	vivadotcl2

report_drc2default:defaultZ4-42h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2 
report_drc: 2default:default2
00:00:112default:default2
00:00:062default:default2
2984.6682default:default2
0.0002default:defaultZ17-268h px? 
?
%s4*runtcl2?
?Executing : report_methodology -file design_v3_wrapper_methodology_drc_routed.rpt -pb design_v3_wrapper_methodology_drc_routed.pb -rpx design_v3_wrapper_methodology_drc_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_methodology -file design_v3_wrapper_methodology_drc_routed.rpt -pb design_v3_wrapper_methodology_drc_routed.pb -rpx design_v3_wrapper_methodology_drc_routed.rpx2default:defaultZ4-113h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
Y
$Running Methodology with %s threads
74*drc2
22default:defaultZ23-133h px? 
?
2The results of Report Methodology are in file %s.
450*coretcl2?
?C:/Users/Projet/Desktop/Recherche/gallay_DDR_ZC706/workspace/AXI_DDR_ZC706/AXI_DDR_ZC706.runs/impl_1/design_v3_wrapper_methodology_drc_routed.rpt?C:/Users/Projet/Desktop/Recherche/gallay_DDR_ZC706/workspace/AXI_DDR_ZC706/AXI_DDR_ZC706.runs/impl_1/design_v3_wrapper_methodology_drc_routed.rpt2default:default8Z2-1520h px? 
d
%s completed successfully
29*	vivadotcl2&
report_methodology2default:defaultZ4-42h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2(
report_methodology: 2default:default2
00:00:232default:default2
00:00:142default:default2
3126.2662default:default2
141.5982default:defaultZ17-268h px? 
?
%s4*runtcl2?
?Executing : report_power -file design_v3_wrapper_power_routed.rpt -pb design_v3_wrapper_power_summary_routed.pb -rpx design_v3_wrapper_power_routed.rpx
2default:defaulth px? 
?
Command: %s
53*	vivadotcl2?
?report_power -file design_v3_wrapper_power_routed.rpt -pb design_v3_wrapper_power_summary_routed.pb -rpx design_v3_wrapper_power_routed.rpx2default:defaultZ4-113h px? 
E
%Done setting XDC timing constraints.
35*timingZ38-35h px? 
K
,Running Vector-less Activity Propagation...
51*powerZ33-51h px? 
P
3
Finished Running Vector-less Activity Propagation
1*powerZ33-1h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
1552default:default2
252default:default2
102default:default2
02default:defaultZ4-41h px? 
^
%s completed successfully
29*	vivadotcl2 
report_power2default:defaultZ4-42h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2"
report_power: 2default:default2
00:00:232default:default2
00:00:142default:default2
3145.6952default:default2
19.4302default:defaultZ17-268h px? 
?
%s4*runtcl2?
oExecuting : report_route_status -file design_v3_wrapper_route_status.rpt -pb design_v3_wrapper_route_status.pb
2default:defaulth px? 
?
%s4*runtcl2?
?Executing : report_timing_summary -max_paths 10 -file design_v3_wrapper_timing_summary_routed.rpt -pb design_v3_wrapper_timing_summary_routed.pb -rpx design_v3_wrapper_timing_summary_routed.rpx -warn_on_violation 
2default:defaulth px? 
r
UpdateTimingParams:%s.
91*timing29
% Speed grade: -2, Delay Type: min_max2default:defaultZ38-91h px? 
|
CMultithreading enabled for timing update using a maximum of %s CPUs155*timing2
22default:defaultZ38-191h px? 
?
%s4*runtcl2n
ZExecuting : report_incremental_reuse -file design_v3_wrapper_incremental_reuse_routed.rpt
2default:defaulth px? 
g
BIncremental flow is disabled. No incremental reuse Info to report.423*	vivadotclZ4-1062h px? 
?
%s4*runtcl2n
ZExecuting : report_clock_utilization -file design_v3_wrapper_clock_utilization_routed.rpt
2default:defaulth px? 
?
%s4*runtcl2?
?Executing : report_bus_skew -warn_on_violation -file design_v3_wrapper_bus_skew_routed.rpt -pb design_v3_wrapper_bus_skew_routed.pb -rpx design_v3_wrapper_bus_skew_routed.rpx
2default:defaulth px? 
r
UpdateTimingParams:%s.
91*timing29
% Speed grade: -2, Delay Type: min_max2default:defaultZ38-91h px? 
|
CMultithreading enabled for timing update using a maximum of %s CPUs155*timing2
22default:defaultZ38-191h px? 


End Record
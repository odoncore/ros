/* definitions of builtin command list - automatically generated, do not edit */
#include "px4_posix.h"
#include "px4_log.h"

#include "apps.h"

#include <cstdio>
#include <map>
#include <string>

#include <cstdlib>

extern "C" {

int gps_main(int argc, char *argv[]);
int pwm_out_sim_main(int argc, char *argv[]);
int vmount_main(int argc, char *argv[]);
int accelsim_main(int argc, char *argv[]);
int adcsim_main(int argc, char *argv[]);
int measairspeedsim_main(int argc, char *argv[]);
int barosim_main(int argc, char *argv[]);
int gpssim_main(int argc, char *argv[]);
int gyrosim_main(int argc, char *argv[]);
int rgbledsim_main(int argc, char *argv[]);
int tone_alarm_main(int argc, char *argv[]);
int esc_calib_main(int argc, char *argv[]);
int mixer_main(int argc, char *argv[]);
int param_main(int argc, char *argv[]);
int perf_main(int argc, char *argv[]);
int reboot_main(int argc, char *argv[]);
int sd_bench_main(int argc, char *argv[]);
int listener_main(int argc, char *argv[]);
int ver_main(int argc, char *argv[]);
int top_main(int argc, char *argv[]);
int motor_ramp_main(int argc, char *argv[]);
int attitude_estimator_q_main(int argc, char *argv[]);
int commander_main(int argc, char *argv[]);
int dataman_main(int argc, char *argv[]);
int ekf2_main(int argc, char *argv[]);
int fw_att_control_main(int argc, char *argv[]);
int fw_pos_control_l1_main(int argc, char *argv[]);
int land_detector_main(int argc, char *argv[]);
int logger_main(int argc, char *argv[]);
int mavlink_main(int argc, char *argv[]);
int mc_att_control_main(int argc, char *argv[]);
int mc_pos_control_main(int argc, char *argv[]);
int navigator_main(int argc, char *argv[]);
int position_estimator_inav_main(int argc, char *argv[]);
int local_position_estimator_main(int argc, char *argv[]);
int replay_main(int argc, char *argv[]);
int sdlog2_main(int argc, char *argv[]);
int sensors_main(int argc, char *argv[]);
int simulator_main(int argc, char *argv[]);
int uorb_main(int argc, char *argv[]);
int vtol_att_control_main(int argc, char *argv[]);
int px4_simple_app_main(int argc, char *argv[]);
int mc_att_control_m_main(int argc, char *argv[]);
int mc_pos_control_m_main(int argc, char *argv[]);
int ekf_att_pos_estimator_main(int argc, char *argv[]);
int attitude_estimator_ekf_main(int argc, char *argv[]);
int ex_fixedwing_control_main(int argc, char *argv[]);
int sf0x_tests_main(int argc, char *argv[]);
int rc_tests_main(int argc, char *argv[]);
int commander_tests_main(int argc, char *argv[]);
int mc_pos_control_tests_main(int argc, char *argv[]);
int controllib_test_main(int argc, char *argv[]);
int uorb_tests_main(int argc, char *argv[]);
int tests_main(int argc, char *argv[]);

int shutdown_main(int argc, char *argv[]);
int list_tasks_main(int argc, char *argv[]);
int list_files_main(int argc, char *argv[]);
int list_devices_main(int argc, char *argv[]);
int list_topics_main(int argc, char *argv[]);
int sleep_main(int argc, char *argv[]);

}

extern void px4_show_devices(void);

void init_app_map(apps_map_type &apps)
{
	apps["gps"] = gps_main;
	apps["pwm_out_sim"] = pwm_out_sim_main;
	apps["vmount"] = vmount_main;
	apps["accelsim"] = accelsim_main;
	apps["adcsim"] = adcsim_main;
	apps["measairspeedsim"] = measairspeedsim_main;
	apps["barosim"] = barosim_main;
	apps["gpssim"] = gpssim_main;
	apps["gyrosim"] = gyrosim_main;
	apps["rgbledsim"] = rgbledsim_main;
	apps["tone_alarm"] = tone_alarm_main;
	apps["esc_calib"] = esc_calib_main;
	apps["mixer"] = mixer_main;
	apps["param"] = param_main;
	apps["perf"] = perf_main;
	apps["reboot"] = reboot_main;
	apps["sd_bench"] = sd_bench_main;
	apps["listener"] = listener_main;
	apps["ver"] = ver_main;
	apps["top"] = top_main;
	apps["motor_ramp"] = motor_ramp_main;
	apps["attitude_estimator_q"] = attitude_estimator_q_main;
	apps["commander"] = commander_main;
	apps["dataman"] = dataman_main;
	apps["ekf2"] = ekf2_main;
	apps["fw_att_control"] = fw_att_control_main;
	apps["fw_pos_control_l1"] = fw_pos_control_l1_main;
	apps["land_detector"] = land_detector_main;
	apps["logger"] = logger_main;
	apps["mavlink"] = mavlink_main;
	apps["mc_att_control"] = mc_att_control_main;
	apps["mc_pos_control"] = mc_pos_control_main;
	apps["navigator"] = navigator_main;
	apps["position_estimator_inav"] = position_estimator_inav_main;
	apps["local_position_estimator"] = local_position_estimator_main;
	apps["replay"] = replay_main;
	apps["sdlog2"] = sdlog2_main;
	apps["sensors"] = sensors_main;
	apps["simulator"] = simulator_main;
	apps["uorb"] = uorb_main;
	apps["vtol_att_control"] = vtol_att_control_main;
	apps["px4_simple_app"] = px4_simple_app_main;
	apps["mc_att_control_m"] = mc_att_control_m_main;
	apps["mc_pos_control_m"] = mc_pos_control_m_main;
	apps["ekf_att_pos_estimator"] = ekf_att_pos_estimator_main;
	apps["attitude_estimator_ekf"] = attitude_estimator_ekf_main;
	apps["ex_fixedwing_control"] = ex_fixedwing_control_main;
	apps["sf0x_tests"] = sf0x_tests_main;
	apps["rc_tests"] = rc_tests_main;
	apps["commander_tests"] = commander_tests_main;
	apps["mc_pos_control_tests"] = mc_pos_control_tests_main;
	apps["controllib_test"] = controllib_test_main;
	apps["uorb_tests"] = uorb_tests_main;
	apps["tests"] = tests_main;

	apps["shutdown"] = shutdown_main;
	apps["list_tasks"] = list_tasks_main;
	apps["list_files"] = list_files_main;
	apps["list_devices"] = list_devices_main;
	apps["list_topics"] = list_topics_main;
	apps["sleep"] = sleep_main;
}

void list_builtins(apps_map_type &apps)
{
	PX4_INFO("Builtin Commands:\n");
	for (apps_map_type::iterator it = apps.begin(); it != apps.end(); ++it)
		PX4_INFO("%s : 0x%x\n", it->first.c_str(), it->second);
}

int shutdown_main(int argc, char *argv[])
{
	printf("Shutting down\n");
	exit(0);
}

int list_tasks_main(int argc, char *argv[])
{
	px4_show_tasks();
	return 0;
}

int list_devices_main(int argc, char *argv[])
{
	px4_show_devices();
	return 0;
}

int list_topics_main(int argc, char *argv[])
{
	px4_show_topics();
	return 0;
}

int list_files_main(int argc, char *argv[])
{
	px4_show_files();
	return 0;
}

int sleep_main(int argc, char *argv[])
{
        if (argc != 2) {
           PX4_WARN( "Usage: sleep <seconds>" );
           return 1;
        }

        unsigned long usecs = 1000000UL * atol(argv[1]);
        printf("Sleeping for %s s; (%lu us).\n", argv[1], usecs);
        usleep(usecs);
        return 0;
}

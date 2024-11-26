#ifndef REKERNEL_H
#define REKERNEL_H

#include <linux/init.h>
#include <linux/types.h>
#include <net/sock.h>
#include <linux/netlink.h>
#include <linux/proc_fs.h>
#include <linux/freezer.h>
#include <linux/cgroup.h>

#define NETLINK_REKERNEL_MAX 26
#define NETLINK_REKERNEL_MIN 22
#define USER_PORT 100
#define PACKET_SIZE 128
#define MIN_USERAPP_UID (10000)
#define MAX_SYSTEM_UID (2000)
#define RESERVE_ORDER 17
#define WARN_AHEAD_SPACE (1 << RESERVE_ORDER)

extern struct net init_net;

static inline bool line_is_frozen(struct task_struct *task)
{
	return (freezing(task) || frozen(task) || cgroup_task_freeze(task) || cgroup_task_frozen(task));
}

int send_netlink_message(char *msg, uint16_t len);

#endif
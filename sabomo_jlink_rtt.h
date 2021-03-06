#pragma once
/**
 * @file sabomo_jlink_rtt.h
 * @author James Wang (woodsking2@hotmail.com)
 * @brief 使用rtt 作为stream 输出输入
 * @version 0.1
 * @date 2020-04-09
 *
 * @copyright Copyright (c) 2020
 *
 */
#include "mbed.h"
#include "sabomo_non_copyable.h"
#include "sabomo_thread_safe.h"
namespace sabomo
{
class Jlink_rtt : public mbed::Stream, private Non_copyable<Jlink_rtt>, impl::Thread_safe
{
  public:
    Jlink_rtt(const char *name = "Jlink_rtt");
    Jlink_rtt(const Jlink_rtt &) = delete;
    Jlink_rtt &operator=(const Jlink_rtt &) = delete;
    Jlink_rtt(Jlink_rtt &&) = delete;
    Jlink_rtt &operator=(Jlink_rtt &&) = delete;

  protected:
    using Stream::lock;
    using Stream::unlock;
    int _getc() override;
    int _putc(int c) override;
    void lock() override;
    void unlock() override;
    PlatformMutex _mutex;
};
} // namespace sabomo

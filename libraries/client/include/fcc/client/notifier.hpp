#pragma once
#include <memory>
#include <string>
#include <stdint.h>

#include <fc/time.hpp>

namespace mcc { namespace client { 
  namespace detail {
    class mcc_gntp_notifier_impl;
  }

  class mcc_gntp_notifier {
  public:
    mcc_gntp_notifier(const std::string& host_to_notify = "127.0.0.1", uint16_t port = 23053,
                      const std::string& mcc_instance_identifier = "FCCShares",
                      const fc::optional<std::string>& password = fc::optional<std::string>());
    ~mcc_gntp_notifier();

    void client_is_shutting_down();
    void notify_connection_count_changed(uint32_t new_connection_count);
    void notify_client_exiting_unexpectedly();
    void notify_head_block_too_old(const fc::time_point_sec head_block_age);
  private:
    std::unique_ptr<detail::mcc_gntp_notifier_impl> my;
  };
  typedef std::shared_ptr<mcc_gntp_notifier> mcc_gntp_notifier_ptr;

} } // end namespace mcc::client

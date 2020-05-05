#pragma once

#include "mavlink_include.h"
#include "plugins/log_files/log_files.h"
#include "plugin_impl_base.h"
#include "system.h"
#include <fstream>

namespace mavsdk {

class LogFilesImpl : public PluginImplBase {
public:
    LogFilesImpl(System& system);
    ~LogFilesImpl();

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;

    std::pair<LogFiles::Result, std::vector<LogFiles::Entry>> get_entries();
    void get_entries_async(LogFiles::get_entries_callback_t callback);

    LogFiles::Result download_log_file(unsigned id, const std::string& file_path);
    void download_log_file_async(
        unsigned id, const std::string& file_path, LogFiles::download_log_file_callback_t callback);

private:
    void request_end();

    void process_log_entry(const mavlink_message_t& message);
    void process_log_data(const mavlink_message_t& message);
    void list_timeout();

    void request_list_entry(int entry_id);

    void check_part();
    void request_log_data(unsigned id, unsigned start, unsigned count);
    void data_timeout();

    bool start_logfile(const std::string& path);
    void write_part_to_disk();
    void finish_logfile();
    void report_progress(unsigned transferred, unsigned total);

    std::size_t determine_part_end();
    void reset_data();

    static constexpr double LIST_TIMEOUT_S = 0.2;
    static constexpr double DATA_TIMEOUT_S = 0.1;

    Time _time{};

    struct {
        std::mutex mutex{};
        std::map<unsigned, LogFiles::Entry> entry_map{};
        LogFiles::get_entries_callback_t callback{nullptr};
        unsigned max_list_id{0};
        unsigned retries{0};
        void* cookie{nullptr};
    } _entries{};

    // We download data in parts of 512 * 90 bytes.
    // If we request the whole file at once we get too much data at once and
    // can't keep up (at least for PX4 SITL). Also, we need to keep track of
    // way too many parts which makes the progress and re-transmission
    // calculation too expensive.
    //
    // This is very much inspired from how QGroundControl does it.
    static constexpr unsigned PART_SIZE = 512;
    // A part refers to the

    struct {
        std::mutex mutex{};
        void* cookie{nullptr};
        unsigned id{0};
        unsigned bytes_to_get{0};
        std::vector<uint8_t> bytes{};
        std::vector<bool> chunks_received{};
        std::size_t part_start{0};
        unsigned retries{0};
        bool rerequesting{false};
        int last_ofs_rerequested{-1};
        dl_time_t time_started{};
        std::ofstream file{};
        LogFiles::download_log_file_callback_t callback{nullptr};
    } _data{};
};

} // namespace mavsdk

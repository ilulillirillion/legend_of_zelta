#include <iostream> // For cout and endl.
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" // For colorized stdout logger.
//#include "spdlog/sinks/rotating_file_sink.h" // For rotating file logger.
#include "spdlog/sinks/basic_file_sink.h"

int main(int, char* []) {
  try {

    // Create a vector for sinks to ultimately pass to the logger constructor.
    std::vector<spdlog::sink_ptr> sinks;

    // Create a stdout logger with color.
    //auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    //sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

    //sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);
    console_sink->set_pattern("[multi_sink_test] [%^%l%$] %v");
    sinks.push_back(console_sink);

    //std::make_shared<spdlog::sinks::stdout_color_sink_mt>() console_sink;
    //console_sink->set_level(spdlog::level::debug);
    //console_sink->set_pattern("[multi_sink_example] [%^%l%$] %v");
    //sinks.push_back(console_sink);

    // Create a rotating file logger with 5mb size max and 3 rotated files.
    //sinks.push_back(spdlog::rotating_logger_mt("file_logger", "myfilename", 1024 * 1024 * 5, 3));

    //sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("testlog.txt", true));
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("testlog.txt", true);
    file_sink->set_level(spdlog::level::debug);
    sinks.push_back(file_sink);

    //auto file_sink = spdlog::rotating_logger_mt("file_logger", "myfilename", 1024 * 1024 * 5, 3);
    //std::make_shared<spdlog::rotating_logger_mt>("file_logger", "myfilename", 1024 * 1024 * 5, 3); file_sink;
    //file_sink->set_level(spdlog::level::debug);
    //sinks.push_back(*file_sink);

    //std::make_shared<spdlog::logger> logger("multi_sink", {console_sink, file_sink});
    //spdlog::logger logger("multi_sink", spdlog::sinks_init_list({console_sink, file_sink}));

    //spdlog::logger logger("multi_sink", begin(sinks), end(sinks));
    auto main_logger = std::make_shared<spdlog::logger>("main", begin(sinks), end(sinks));

    //spdlog::logger logger("multi_sink", {console_sink, file_sink});
    //auto logger = spdlog::logger("multi_sink", {console_sink, file_sink});
    main_logger->set_level(spdlog::level::trace);

    //spdlog::register_logger(std::shared_ptr<logger>);
    //spdlog::register_logger("multi_sink");
    //spdlog::get("multi_sink")->error("test error");
    spdlog::register_logger(main_logger);
    spdlog::get("main")->error("test error");
    

    //spdlog::error("test error");
    
  } 

  catch (const spdlog::spdlog_ex& ex) {
    std::cout << "Log initialization failed: " << ex.what() << std::endl;

  }
}

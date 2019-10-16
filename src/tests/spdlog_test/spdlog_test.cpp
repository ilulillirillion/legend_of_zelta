#include <iostream> // For cout and endl.
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" // For colorized stdout logger.
#include "spdlog/sinks/basic_file_sink.h" // For file sink.

int main(int, char* []) {
  try {

    // Create a vector for sinks to ultimately pass to the logger constructor.
    std::vector<spdlog::sink_ptr> sinks;

    // Create a multi-threaded stdout sink with color.
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);
    console_sink->set_pattern("[multi_sink_test] [%^%l%$] %v");
    sinks.push_back(console_sink);

    // Create a basic multi-threaded file sink.
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("testlog.txt", true);
    file_sink->set_level(spdlog::level::debug);
    sinks.push_back(file_sink);

    // Create a main logger using the stdout and file sinks.
    auto main_logger = std::make_shared<spdlog::logger>("main", begin(sinks), end(sinks));
    main_logger->set_level(spdlog::level::trace);

    // Register the main logger so that is accessible globally by name.
    spdlog::register_logger(main_logger);

    // Perform a test log at each level.
    spdlog::get("main")->trace("test trace");
    spdlog::get("main")->debug("test debug");
    spdlog::get("main")->info("test info");
    spdlog::get("main")->warn("test warn");
    spdlog::get("main")->error("test error");
    spdlog::get("main")->critical("test critical");

    // Log that the main logger has been built.
    spdlog::get("main")->info("Finished building main logger.");
    
  } 

  catch (const spdlog::spdlog_ex& ex) {

    // Print the logger initialization failure along with the error.
    std::cout << "Log initialization failed: " << ex.what() << std::endl;

  }
}

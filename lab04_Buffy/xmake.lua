add_rules("mode.debug", "mode.release")

target("buffy")
    set_kind("binary")
    add_files("src/**.cpp")

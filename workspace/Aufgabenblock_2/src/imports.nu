let imports = (open ./import.txt | lines);
let files = (ls ./*.cpp | append (ls ./*.h) | get name);
$files | each { |file|
    let content = (open $file | lines);
    let $is_header = { |line|
        (
            $line | str starts-with "#ifndef"
        ) or (
            $line | str starts-with "#define"
        )
    };
    let header = ($content | take while $is_header | str join "\n");
    let body = ($content | skip while $is_header | str join "\n");
    let imports = ($imports | filter { |import|
        (
            $import == ""
        ) or (
            $import | str starts-with "using"
        ) or (
            $content | any { $in | str starts-with $import }
        )
    });
    let imports = $imports | enumerate | filter { |it|
        not (
            (
                $it.item == ""
            ) and (
                (try { $imports | get ($it.index - 1) }) == ""
            )
        )
    } | get item;
    let imports = if ($imports | last) == "" {
        $imports | drop
    } else {
        $imports
    };
    let imports = ($imports | str join "\n");
    if ($file | str ends-with ".h") {
        $header + "\n\n" + $imports + "\nSORTED_INCLUDES\n" + $body + "\n"
    } else {
        $imports + "\nSORTED_INCLUDES\n" + $body + "\n"
    } | save -f $file
}

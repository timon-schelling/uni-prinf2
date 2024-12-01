cd $env.FILE_PWD

let container_name = pwd | path relative-to "~" | path split | str join "-"

if ((podman restart $container_name | complete | get exit_code ) == 0) {
    print $"Container ($container_name) restarted";
    exit 0;
}

let eclipse_tar = "./eclipse-cpp.tar.gz"
let eclipse_url = "https://mirror.ibcp.fr/pub/eclipse/technology/epp/downloads/release/2024-09/R/eclipse-cpp-2024-09-R-linux-gtk-x86_64.tar.gz"

if not ($eclipse_tar | path exists) {
    http get $eclipse_url | save $eclipse_tar
}

podman build -t $container_name .
print $"Container ($container_name) built";


mkdir workspace

(
    podman run
    --volume $"($env.XDG_RUNTIME_DIR)/($env.WAYLAND_DISPLAY):/tmp/wayland-0"
    -it
    --replace
    -v $"(pwd)/workspace:/workspace"
    --name $container_name
    -d
    $container_name
)
print $"Container ($container_name) created and started";

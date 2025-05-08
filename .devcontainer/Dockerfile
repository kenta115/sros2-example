# Use the [Choice] comment to indicate option arguments that should appear in VS Code UX. Use a comma separated list.
#
# [Choice] ROS2 version: humble, jazzy
ARG VARIANT="jazzy"
FROM ros:${VARIANT}

# Use the [Option] comment to specify true/false arguments that should appear in VS Code UX
#
# [Option] Install zsh
ARG INSTALL_ZSH="false"
# [Option] Upgrade OS packages to their latest versions
ARG UPGRADE_PACKAGES="false"
# Install needed packages and setup non-root user. Use a separate RUN statement to add your own dependencies.
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID
# Install needed packages and setup non-root user. Use a separate RUN statement to add your own dependencies.
COPY library-scripts/*.sh library-scripts/*.env /tmp/library-scripts/
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && /bin/bash /tmp/library-scripts/common-debian.sh "${INSTALL_ZSH}" "${USERNAME}" "${USER_UID}" "${USER_GID}" "${UPGRADE_PACKAGES}" "true" "true" \
    #
    && apt-get -y install --no-install-recommends \
    # ****************************************************************************
    # * Add any additional OS packages you want included in the definition here. *
    # * We want to do this before cleanup to keep the "layer" small.             *
    # ****************************************************************************
        bash-completion \
        ros-humble-rmw-cyclonedds-cpp \
    && echo "\n\
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash\n\
source /opt/ros/\${ROS_DISTRO}/setup.bash\n\
" >> /home/${USERNAME}/.bashrc \
    #
    && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/* /tmp/library-scripts

# [Optional] Uncomment this section to install additional OS packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>

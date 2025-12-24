ARG IMAGE_TAG="24.04"

FROM ubuntu:${IMAGE_TAG}

RUN apt update && \
    apt upgrade -y && \
    apt install -y zsh bash tmux git tree wget curl jq python3 python3-pip python3-venv python-is-python3 ripgrep fzf fd-find neofetch && \
    apt install -y build-essential clang gcc-14 g++-14 gdb lldb cmake ninja-build zip unzip tar pkg-config bison flex autoconf -y

RUN LAZYGIT_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | \grep -Po '"tag_name": *"v\K[^"]*') && \
    curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/download/v${LAZYGIT_VERSION}/lazygit_${LAZYGIT_VERSION}_Linux_x86_64.tar.gz" && \
    tar xf lazygit.tar.gz lazygit && \
    install lazygit -D -t /usr/local/bin/

RUN curl -LO https://github.com/neovim/neovim/releases/download/v0.11.5/nvim-linux-x86_64.tar.gz && \
    tar -C /opt -xzf nvim-linux-x86_64.tar.gz && \
    rm nvim-linux-x86_64.tar.gz && \
    ln -s /opt/nvim-linux-x86_64/bin/nvim /opt/nvim-linux-x86_64/bin/vim

ENV PATH="$PATH:/opt/nvim-linux-x86_64/bin"

RUN deluser ubuntu && \
    groupadd -g 1000 dev && \
    useradd -u 1000 -g dev -d /home/dev dev

RUN apt install -y locales locales-all
ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8

USER dev
WORKDIR /home/dev

ENV SHELL=/usr/bin/zsh
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

RUN mkdir -p ~/.config && \
    git clone https://github.com/LazyVim/starter ~/.config/nvim && \
    rm -rf ~/.config/nvim/.git

RUN mkdir -p ~/.venv && \
    python -m venv ~/.venv/pipx && \
    . ~/.venv/pipx/bin/activate && \
    python -m pip install pipx && \
    mkdir -p ~/.local/bin && \
    ln -s ~/.venv/pipx/bin/pipx ~/.local/bin/pipx

ENV PATH="$PATH:/home/dev/.local/bin"

RUN pipx install tmuxp

RUN git clone --depth 1 --branch v3.1.0 https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

COPY --chown=dev:dev zshrc /home/dev/.zshrc
COPY --chown=dev:dev tmux.conf /home/dev/.tmux.conf

RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.40.3/install.sh | bash && \
    echo ". /home/dev/.zshrc && nvm install --lts" | zsh

RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y

COPY --chown=dev:dev config/nvim/lua/plugins /home/dev/.config/nvim/lua/plugins
COPY --chown=dev:dev config/nvim/lua/config/keymaps.lua /home/dev/.config/nvim/lua/config/keymaps.lua
COPY --chown=dev:dev config/nvim/lazyvim.json /home/dev/.config/nvim/lazyvim.json

RUN curl -fsSL https://claude.ai/install.sh | bash
RUN echo ". /home/dev/.zshrc && npm i -g @openai/codex" | zsh
RUN curl -fsSL https://opencode.ai/install | bash
RUN echo ". /home/dev/.zshrc && npm install -g @google/gemini-cli" | zsh
RUN curl -fsSL https://gh.io/copilot-install | bash
RUN echo ". /home/dev/.zshrc && npm install -g @google/jules" | zsh

USER root
RUN apt install libtool -y
USER dev

WORKDIR /home/dev/code


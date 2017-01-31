# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure("2") do |config|
  # see https://docs.vagrantup.com for more information

  # We're going to run on ubuntu, 32 bit, 14.04
  config.vm.box = "ubuntu/trusty32"

  # Share an additional folder to the guest VM. The first argument is
  # the path on the host to the actual folder. The second argument is
  # the path on the guest to mount the folder. And the optional third
  # argument is a set of non-required options.
  # config.vm.synced_folder "../data", "/vagrant_data"

  # Provider-specific configuration so you can fine-tune various
  # backing providers for Vagrant. These expose provider-specific options.
  config.vm.provider "virtualbox" do |vb|
    vb.memory = "1024"
  end

  # Enable provisioning with a shell script. Additional provisioners such as
  # Puppet, Chef, Ansible, Salt, and Docker are also available. Please see the
  # documentation for more information about their specific syntax and use.
  config.vm.provision "shell", inline: <<-SHELL
    apt-get update
    sudo apt-get install -y git
    # 1) clone the gcc6809 source. TODO: it may be better to just have the binary
    git clone https://LuskeyNoah@bitbucket.org/LuskeyNoah/gcc-4.3.4-6809.git
    # 2) get the necessary dependencies to build gcc
    sudo apt-get install -y libgmp-dev libmpfr-dev
    # 3) go into the gcc6809 directory and build everything
    cd gcc-4.3.4-6809/build-6809
    sudo make everything
    # 4) Go back to the home directory and clone the freewpc repository
    cd ../..
    git clone https://github.com/LuskeyNoah/freewpc.git
    # 5) We should be good to go. Ssh into the machine and try building freewpc!
    #    though just to be friendly, I'm going to go ahead and copy you a .config file
    cd freewpc
    cp config.example .config
    cd ..
  SHELL
end

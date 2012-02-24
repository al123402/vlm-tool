%define	ver	1.0.0
%define	rel	1
%define	prefix	/usr

Prefix:	%{prefix}

Summary       : Hightlight interesting /var/log/messages entries
Name          : vlm-tool
Version       : %{ver}
Release       : %{rel}
License       : GPLv2
Group         : User Interface/Desktops
Source        : %{name}-%{version}.tar.bz2
BuildRoot     : %{_tmppath}/%{name}-%{version}-root
BuildRequires : autoconf,automake
Requires      : python >= 2.6
BuildArch     : noarch

%description
Wholesome goodness
%prep
%setup -q

%build

%install
	rm -rf %{buildroot}
	make prefix=$RPM_BUILD_ROOT%{prefix} install

%clean
	rm -rf %{buildroot}

%files
%defattr(-, root, root)
%doc AUTHORS
%doc COPYING
%doc ChangeLog
%doc INSTALL
%doc NEWS
%doc README
%{_bindir}/vlm-tool
%{_mandir}/man1/vlm-tool.1.gz

%changelog

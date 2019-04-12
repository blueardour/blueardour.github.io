# Steps for install
Follow [https://help.github.com/en/articles/setting-up-your-github-pages-site-locally-with-jekyll](https://help.github.com/en/articles/setting-up-your-github-pages-site-locally-with-jekyll)

problems might occur:

# 1.find_spec_for_exe': can't find gem bundler (>= 0.a) with executable bundle

Bundler 2 introduced a new feature that will automatically switch between Bundler v1 and v2 based on the lockfile. This feature is enabled by RubyGems (only on versions 2.7.0+) which unfortunately has a bug when you run Bundler without the appropriate version installed. You may encounter an error message like:

Can't find gem bundler (>= 0.a) with executable bundle (Gem::GemNotFoundException)
If you do, it can be fixed by installing the version of Bundler that is declared in the lockfile.

$ `cat Gemfile.lock | grep -A 1 "BUNDLED WITH"`
BUNDLED WITH
   1.17.3

$ `gem install bundler -v '1.17.3'`

This bug was fixed in RubyGems 3.0.0 but backports are now being prepared for previous major versions of RubyGems. We’ll let you know when they become available.

refer: [https://bundler.io/blog/2019/01/04/an-update-on-the-bundler-2-release.html](https://bundler.io/blog/2019/01/04/an-update-on-the-bundler-2-release.html)

# 2.mkmf.rb can't find header files for ruby at /usr/lib/ruby/include/ruby.h

to solve: make sure ruby-dev is installed

refer:

[https://stackoverflow.com/questions/4304438/gem-install-failed-to-build-gem-native-extension-cant-find-header-files/27158307](https://stackoverflow.com/questions/4304438/gem-install-failed-to-build-gem-native-extension-cant-find-header-files/27158307)

# 3.`sudo gem install json -v  '1.8.3'`

`current directory: /var/lib/gems/2.5.0/gems/json-1.8.3/ext/json/ext/generator
make "DESTDIR=" clean

current directory: /var/lib/gems/2.5.0/gems/json-1.8.3/ext/json/ext/generator
make "DESTDIR="
compiling generator.c
generator.c: In function ‘generate_json’:
generator.c:861:25: error: ‘rb_cFixnum’ undeclared (first use in this function); did you mean ‘mFixnum’?
     } else if (klass == rb_cFixnum) {
                         ^~~~~~~~~~
                         mFixnum
generator.c:861:25: note: each undeclared identifier is reported only once for each function it appears in
generator.c:863:25: error: ‘rb_cBignum’ undeclared (first use in this function); did you mean ‘rb_cFixnum’?
     } else if (klass == rb_cBignum) {
                         ^~~~~~~~~~
`

to solver: `sudo gem install json -v  '1.8.5'`

refer:

[https://github.com/rails/rails/issues/27450](https://github.com/rails/rails/issues/27450)

# 4.still error when bundle install because of json version
to solve: `bundle update json`  and `gem update --system`

# 5.other refer
a.[https://stackoverflow.com/questions/7092107/rails-could-not-find-a-javascript-runtime](https://stackoverflow.com/questions/7092107/rails-could-not-find-a-javascript-runtime)

b. [https://github.com/Simpleyyt/jekyll-jacman/issues/14](https://github.com/Simpleyyt/jekyll-jacman/issues/14)

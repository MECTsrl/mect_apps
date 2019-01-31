#!/usr/bin/perl
use strict;
use warnings;

# open page*.ui
# check if some widget don't have set the defaut font, set it as "Dejavu Sans 8"

# check all the page*.ui files
my $file;
foreach $file (glob( 'page*.ui' ))
{
	my $page_name = '';
	my $button_name = '';
	my $line = '';
	my $modified = 0;
	my $missing_font = 0;
	my $missing_font_family = 1;
	my $missing_font_pointsize = 1;
	my @buttonlist;
	print "Check for widget with default fonts '" . $file . "'\n";
	open INFILE, "<", $file or die $!;
	open TMP, "+>", undef or die $!;
	while (<INFILE>)
	{
		$line = $_;
		chomp($line);
		$line =~ s/\\//g;
		$line =~ s/^\s+//;
		$line =~ s/\s+$//;	
		if ($line =~ /<widget class=/)
		{
			$missing_font = 1;
			$missing_font_family = 1;
			$missing_font_pointsize = 1;
		}
		elsif ($line =~ /<family>/)
		{
			$missing_font_family = 0;
		}
		elsif ($line =~ /<pointsize>/)
		{
			$missing_font_pointsize = 0;
		}
		elsif ($line =~ /<\/widget>/ && $missing_font == 1)
		{
			print "Adding font family and size.\n";
			print TMP "<property name=\"font\">\n";
			print TMP " <font>\n";
			print TMP "  <family>DejaVu Sans</family>\n";
			print TMP "  <pointsize>8</pointsize>\n";
			print TMP " </font>\n";
			print TMP "</property>\n";
			$modified = 1;
			$missing_font = 0;
		}
		elsif ($line =~ /<\/font>/)
		{
			if ($missing_font_family == 1)
			{
				print "Adding font family.\n";
				print TMP "  <family>DejaVu Sans</family>\n";
				$modified = 1;
				$missing_font_family = 0;
			}
			if ($missing_font_pointsize == 1)
			{
				print "Adding font syze.\n";
				print TMP "  <pointsize>8</pointsize>\n";
				$modified = 1;
				$missing_font_pointsize = 0;
			}
		}
		elsif ($line =~ /<font>/)
		{
			$missing_font = 0;
		}
		print TMP $line . "\n";
	}
	close INFILE;

	if ($modified == 1)
	{
		open INFILE, ">", $file or die $!;

		# Move to the beginning of file
		seek(TMP,0,0);
		# Read contents of the anonymous file
		while (<TMP>) {
			print INFILE $_;
		}
		close INFILE;
	}
	close TMP;

}

# launch Crosstable Compiler (here for working with mect_suite_2.0 projects too)
print "Crosstable compiler ...\n";
my @cmds = ("C:/Qt485/desktop/bin/ctc.exe",
            "-c", "config/Crosstable.csv",
            "-g", "plc/Crosstable.gvl",
            "-i", "config/Crosstable.h",
            "-s", "config/Crosstable.cpp");
system { $cmds[0] } @cmds ;
if ($? != 0) {
  print "... Crosstable compiler error\n";
} else {
  print "... Crosstable compiler OK\n";
}


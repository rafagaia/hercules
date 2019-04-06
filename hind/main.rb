# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.rb                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 23:23:57 by rgaia             #+#    #+#              #
#    Updated: 2019/03/16 00:30:31 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require "oauth2"

UID = '7c7f455818f2227b80eddc3e42459be7e03073398a202be2ec3349d44580cd78'
SECRET = '727fda3a8e66f489d4a3c217c723b1b698fc6be5e59cc25d626f754876e5595b'

if ARGV.length != 1
	abort "Error: Needs One (1) File of User_ids\n"
end

client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
token = client.client_credentials.get_token

File.open(ARGV[0], "r") do |f1_userids|
	for line in f1_userids
		begin
			user_id = line.strip
			response = token.get("/v2/users/#{user_id.strip}/locations")
			if response.parsed[0]["host"]
				student = response.parsed[0]["host"]
				puts "ID #{user_id.strip} is at: #{student.strip}."
			end
		rescue
			puts "ID #{user_id} is not at Computers."
		end
	end
	f1_userids.close
end
